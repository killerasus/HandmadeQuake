#include "host.h"

double realtime = 0;
double oldrealtime = 0;
double host_frametime = 0;

void Host_Init(void)
{

}

qboolean Host_FilterTime(float time)
{
	realtime += time;
	float timediff = realtime - oldrealtime;

	if (timediff < 1.0 / 72.0)
	{
		return false;
	}
	else
	{
		host_frametime = timediff;
		oldrealtime = realtime;
		return true;
	}
}

void Host_Frame(float timestep)
{
	if (!Host_FilterTime(timestep))
	{
		return;
	}

	// Update game
	// Render scene
}

void Host_Shutdown(void)
{

}