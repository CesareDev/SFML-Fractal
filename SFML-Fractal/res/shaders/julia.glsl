#version 440 core

#define MAX_STEPS 100

vec2 mul(vec2 a, vec2 b)
{
	return vec2
	(
		a.x * b.x - a.y * b.y,
		a.x * b.y + a.y * b.x
	);
}

uniform vec2 u_ViewportSize;
uniform vec2 u_ViewportOffset;
uniform vec2 u_CameraPosition;
uniform float u_Scale;
uniform vec2 u_MousePosition;

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

	float imgStartParam = -1.f;
	float imgEndParam = 1.f;
	float realStartParam = imgStartParam * ratio;
	float realEndParam = imgEndParam * ratio;
	vec2 mpos = vec2(u_MousePosition.x, u_ViewportSize.y - u_MousePosition.y);

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
		realStartParam + ((mpos.x - u_ViewportOffset.x) / u_ViewportSize.x) * (realEndParam - realStartParam),
		imgStartParam + ((mpos.y - u_ViewportOffset.y) / u_ViewportSize.y) * (imgEndParam - imgStartParam)
	);

	vec2 z = vec2
	(
		realStart + ((gl_FragCoord.x - u_ViewportOffset.x) / u_ViewportSize.x) * (realEnd - realStart),
		imgStart + ((gl_FragCoord.y - u_ViewportOffset.y) / u_ViewportSize.y) * (imgEnd - imgStart)
	);

	int n;
	while (dot(z, z) <= 4.f && n < MAX_STEPS)
	{
		z = mul(z, z) + c;
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