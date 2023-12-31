#version 440 core

#define MAX_STEPS 100

vec2 square(vec2 a)
{
	return vec2
	(
		a.x * a.x - a.y * a.y,
		2.f * a.x * a.y
	);
}

vec2 div(vec2 a, vec2 b)
{
	float den = dot(b, b);
	return vec2
	(
		dot(a, b) / den,
		(a.y * b.x - a.x * b.y) / den
	);
}

uniform vec2 u_ViewportSize;
uniform vec2 u_ViewportOffset;
uniform vec2 u_CameraPosition;
uniform float u_Scale;

vec3 palette[] =
{
	vec3(0.098,0.098,0.098),
	vec3(0.459,0.055,0.129),
	vec3(0.89,0.396,0.114),
	vec3(0.745,0.843,0.329)
};

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

	vec2 c = vec2
	(
		realStart + ((gl_FragCoord.x - u_ViewportOffset.x) / u_ViewportSize.x) * (realEnd - realStart),
		imgStart + ((gl_FragCoord.y - u_ViewportOffset.y) / u_ViewportSize.y) * (imgEnd - imgStart)
	);

	vec2 z;
	int n;
	while (dot(z, z) <= 4.f && n < MAX_STEPS)
	{
		vec2 num = square(z) + c - vec2(1.f, 0.f);
		vec2 den = 2.f * z + c - vec2(2.f, 0.f);
		z = square(div(num, den));
		n++;
	}

	float factor = (float(n) - log2(max(1.f, log2(length(z))))) / MAX_STEPS;
	factor *= palette.length();
	int clr1 = int(factor);
    float t2 = factor - clr1;
    float t1 = 1.f - t2;
    clr1 = clr1 % palette.length();
    int clr2 = (clr1 + 1) % palette.length();

	vec3 color = palette[clr1] * t1 + palette[clr2] * t2;

	gl_FragColor = vec4(color, 1.0);
}