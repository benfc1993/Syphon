#include "sypch.h"
#include "Application.h"

#include "Syphon\Events\ApplicationEvent.h"
#include "Syphon\Log.h"

#include "Platform/Windows/WindowsWindow.h"

namespace Syphon
{
	Application::Application() 
	{
	}

	Application::~Application ()
	{
	}

	void Application::Run ()
	{
		WindowResizeEvent e ( 1366, 786 );

		Window::Create ();

		if (e.IsInCategory ( EventCategoryApplication ))
		{
			SY_TRACE ( e );
		}

		while (true)
		{

		}
	}
}