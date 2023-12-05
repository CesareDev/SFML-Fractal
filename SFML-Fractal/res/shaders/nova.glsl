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

Complex sub(Complex a, Complex b)
{
	return Complex(a.r - b.r, a.i - b.i);
}

Complex mul(Complex a, float k)
{
	return Complex(a.r * k, a.i * k);
}

Complex mul(Complex a, Complex b)
{
	return Complex
	(
		a.r * b.r - a.i * b.i,
		a.r * b.i + a.i * b.r
	);
}

Complex div(Complex a, Complex b)
{
	float den = (b.r * b.r + b.i * b.i);
	return Complex
	(
		(a.r * b.r + a.i * b.i) / den,
		(a.i * b.r - a.r * b.i) / den
	);
}

float abs2(Complex a)
{
	return a.r * a.r + a.i * a.i;
}

uniform vec2 u_ViewportSize;
uniform vec2 u_ViewportOffset;
uniform vec2 u_CameraPosition;
uniform float u_Scale;

uniform vec2 u_RedFrequencyPhase;
uniform vec2 u_GreenFrequencyPhase;
uniform vec2 u_BlueFrequencyPhase;

void main()
{
	float ratio = u_ViewportSize.x / u_ViewportSize.y;
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
		realStart + ((gl_FragCoord.x - u_ViewportOffset.x) / u_ViewportSize.x) * (realEnd - realStart),
		imgStart + ((gl_FragCoord.y - u_ViewportOffset.y) / u_ViewportSize.y) * (imgEnd - imgStart)
	);

	Complex i = Complex(1.f, 0.f);
	Complex z = c;
	float k = 2.f / 3.f;

	int n;
	while (abs2(z) <= 4.f && n < MAX_STEPS)
	{
		Complex z3 = mul(mul(mul(z, z), z), k);
		Complex s = add(z, i);
		z = add(add(div(sub(sub(z3, mul(z, 2.f)), i), mul(s, s)), c), i);
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