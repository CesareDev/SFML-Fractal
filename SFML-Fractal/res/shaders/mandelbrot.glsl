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

	vec2 z;
	int n;
	while (dot(z, z) <= 4.f && n < MAX_STEPS)
	{
		z = square(z) + c;
		n++;
	}

	float factor = (float(n) - log2(max(1.f, log2(length(z))))) / MAX_STEPS;
	gl_FragColor = vec4(factor, factor, factor, 1.0);
}