#include "sypch.h"

#include "WindowsWindow.h"

#include "Syphon/Events/ApplicationEvent.h"
#include "Syphon/Events/MouseEvent.h"
#include "Syphon/Events/KeyEvent.h"

namespace Syphon
{

	static bool s_GLFWInitialised = false;

	static void GLFWErrorCallback( int error, const char* description )
	{
		SY_CORE_ERROR( "GLFW Error ({0}): {1}", error, description );
	}

	Window* Window::Create( const WindowProps& props )
	{
		return new WindowsWindow( props );
	}

	WindowsWindow::WindowsWindow( const WindowProps& props )
	{
		Init( props );
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init( const WindowProps& props )
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		SY_CORE_INFO( "Creating Window {0} {1} {2}", props.Title, props.Width, props.Height );

		if (!s_GLFWInitialised)
		{
			int success = glfwInit();
			SY_CORE_ASSERT( success, "Could not initialize GLFW!" );
			glfwSetErrorCallback( GLFWErrorCallback );
			s_GLFWInitialised = true;
		}

		GLFWmonitor* primary = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode( primary );
		glfwWindowHint( GLFW_REFRESH_RATE, mode->refreshRate );

		SY_CORE_INFO( "Refresh rate: {0}", mode->refreshRate );

		m_Window = glfwCreateWindow( m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr );
		glfwMakeContextCurrent( m_Window );
		glfwSetWindowUserPointer( m_Window, &m_Data );
		SetVSync( false );


		glfwSetWindowSizeCallback( m_Window, []( GLFWwindow* window, int width, int height )
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event( width, height );
				data.EventCallback( event );
			} );

		glfwSetWindowCloseCallback( m_Window, []( GLFWwindow* window )
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
				WindowCloseEvent event;
				data.EventCallback( event );
			} );

		glfwSetKeyCallback( m_Window, []( GLFWwindow* window, int keycode, int scancode, int action, int mods )
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event( keycode, 0 );
						data.EventCallback( event );
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event( keycode );
						data.EventCallback( event );
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event( keycode, 1 );
						data.EventCallback( event );
						break;
					}
				}
			} );

		glfwSetMouseButtonCallback( m_Window, []( GLFWwindow* window, int keycode, int action, int mods )
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event( keycode );
						data.EventCallback( event );
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event( keycode );
						data.EventCallback( event );
						break;
					}
				}
			} );

		glfwSetScrollCallback( m_Window, []( GLFWwindow* window, double xOffset, double yOffset )
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );

				MouseScrolledEvent event( (float)xOffset, (float)yOffset );
				data.EventCallback( event );

			} );

		glfwSetCursorPosCallback( m_Window, []( GLFWwindow* window, double xPos, double yPos )
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer( window );
				MouseMovedEvent event( (float)xPos, (float)yPos );
				data.EventCallback( event );
			} );
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers( m_Window );
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow( m_Window );
	}


	void WindowsWindow::SetVSync( bool enabled )
	{
		if (enabled)
			glfwSwapInterval( 1 );
		else
			glfwSwapInterval( 0 );
		m_Data.VSync = enabled;

	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}
