#version 440 core

#define MAX_STEPS 100

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

float abs(Complex a)
{
	return sqrt(a.r * a.r + a.i * a.i);
}

float abs2(Complex a)
{
	return a.r * a.r + a.i * a.i;
}

uniform vec2 u_WinSize;
uniform vec2 u_CameraPosition;
uniform float u_Scale;

uniform vec2 u_RedFrequencyPhase;
uniform vec2 u_GreenFrequencyPhase;
uniform vec2 u_BlueFrequencyPhase;

void main()
{
	float ratio = u_WinSize.x / u_WinSize.y;
	float imgStart = (-1.f / u_Scale);
	float imgEnd = (1.f / u_Scale);
	float realStart = (imgStart * ratio);
	float realEnd = (imgEnd * ratio);

	imgStart += u_CameraPosition.y;
	imgEnd += u_CameraPosition.y;
	realStart += u_CameraPosition.x;
	realEnd += u_CameraPosition.x;

	Complex c = Complex
	(
		realStart + (gl_FragCoord.x / u_WinSize.x) * (realEnd - realStart),
		imgStart + (gl_FragCoord.y / u_WinSize.y) * (imgEnd - imgStart)
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
		float cindex = float(n) + 1.f - log2(log2(abs2(z)) / 2.f);
		color.x = sin(u_RedFrequencyPhase.x * cindex + u_RedFrequencyPhase.y) * 0.5f + 0.5f;
		color.y = sin(u_GreenFrequencyPhase.x * cindex + u_GreenFrequencyPhase.y) * 0.5f + 0.5f;
		color.z = sin(u_BlueFrequencyPhase.x * cindex + u_BlueFrequencyPhase.y) * 0.5f + 0.5f;
	}

	gl_FragColor = vec4(color, 1.0);
}