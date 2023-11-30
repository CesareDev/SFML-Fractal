#version 330 core

#define MAX_STEPS 200

struct Complex 
{
	float r;
	float i;
};

Complex add(Complex a, Complex b)
{
	return Complex(a.r + b.r, a.i + b.i);
}

Complex mul(Complex a, Complex b)
{
	return Complex
	(
		a.r * b.r - a.i * b.i,
		a.r * b.i + a.i * b.r
	);
}

float abs2(Complex a)
{
	return a.r * a.r + a.i * a.i;
}

vec3 palette[16] = 
{
	vec3(66, 30, 15),
	vec3(25, 7, 26),
	vec3(9, 1, 47),
	vec3(4, 4, 73),
	vec3(0, 7, 100),
	vec3(12, 44, 138),
	vec3(24, 82, 177),
	vec3(57, 125, 209),
	vec3(134, 181, 229),
	vec3(211, 236, 248),
	vec3(241, 233, 191),
	vec3(248, 201, 95),
	vec3(255, 170, 0),
	vec3(204, 128, 0),
	vec3(153, 87, 0),
	vec3(106, 52, 3)
};

uniform vec2 u_WinSize;
uniform vec2 u_CameraPosition;
uniform float u_Scale;

void main()
{
	float ratio = u_WinSize.x / u_WinSize.y;
	float imgStart = -1.f / u_Scale;
	float imgEnd = 1.f / u_Scale;
	float realStart = imgStart * ratio;
	float realEnd = imgEnd * ratio;

	Complex c = Complex
	(
		realStart + (gl_FragCoord.x / u_WinSize.x) * (realEnd - realStart) + u_CameraPosition.x,
		imgStart + (gl_FragCoord.y / u_WinSize.y) * (imgEnd - imgStart) + u_CameraPosition.y
	);

	Complex z;
	int n;
	while (abs2(z) <= 4.f && n < MAX_STEPS)
	{
		z = add(mul(z, z), c);
		n++;
	}

	vec3 color;

	if (n < MAX_STEPS)
	{
		int index = n % palette.length();
		color = palette[index];
		color /= 255.f;
	}

	gl_FragColor = vec4(color, 1.0);
}