#include "sypch.h"
#include "Application.h"

#include "Syphon\Events\ApplicationEvent.h"
#include "Syphon\Log.h"

#include <GLFW/glfw3.h>

namespace Syphon
{
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window> ( Window::Create () );
	}

	Application::~Application ()
	{
	}

	void Application::Run ()
	{
		while (m_Running)
		{
			glClearColor ( 0.12, 0.12, 0.13, 1 );
			glClear (GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate ();
		}
	}
}