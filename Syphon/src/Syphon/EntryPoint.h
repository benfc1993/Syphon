#pragma once

#ifdef SY_PLATFORM_WINDOWS

extern Syphon::Application* Syphon::CreateApplication();

int main( int argc, char** argv )
{
	Syphon::Log::Init();
	SY_CORE_WARN( "Syphon is Logging" );
	int a = 5;
	SY_INFO( "Client Running! Var={0}", a );

	auto app = Syphon::CreateApplication();
	app->Run();
	delete app;
}

#endif // SY_PLATFORM_WINDOWS
