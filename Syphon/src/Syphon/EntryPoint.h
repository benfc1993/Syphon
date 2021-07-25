#pragma once

#ifdef SY_PLATFORM_WINDOWS

extern Syphon::Application* Syphon::CreateApplication ();

int main (int argc, char** argv)
{
	auto app = Syphon::CreateApplication ();
	app->Run ();
	delete app;
}

#endif // SY_PLATFORM_WINDOWS
