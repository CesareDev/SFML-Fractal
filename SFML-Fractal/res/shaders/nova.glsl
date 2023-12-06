#version 440 core

#define MAX_STEPS 100

vec2 third(vec2 a)
{
	float r2 = a.x * a.x;
	float i2 = a.y * a.y;
	return vec2
	(
		a.x * r2 - 3.f * a.x * i2,
		3.f * r2 * a.y - a.y * i2
	);
}

vec2 square(vec2 a)
{
	return vec2
	(
		a.x * a.x - a.y * a.y,
		2.f * a.x * a.y
	);
}

vec2 mul(vec2 a, vec2 b)
{
	return vec2
	(
		a.x * b.x - a.y * b.y,
		a.x * b.y + a.y * b.x
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

	vec2 one = vec2(1.f, 0.f);
	vec2 z = one;

	int n;
	while (dot(z, z) <= 4.f && n < MAX_STEPS)
	{
		z = z - div(third(z) - one, 3.f * square(z)) + c;
		n++;
	}

	float factor = (float(n) - log2(max(1.f, log2(length(z))))) / MAX_STEPS;
	vec3 color = vec3(factor, factor, factor);

	gl_FragColor = vec4(color, 1.0);
}