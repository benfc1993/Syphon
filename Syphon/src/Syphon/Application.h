#pragma once

#include "Core.h"

#include "Window.h"
#include "Events/Event.h"
#include "Syphon/Events/ApplicationEvent.h"
#include "Syphon/LayerStack.h"

namespace Syphon
{
	class SYPHON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent( Event& e );

		void PushLayer( Layer* layer );
		void PopLayer( Layer* layer );

	private:
		bool OnWindowClose( WindowCloseEvent& e );

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	//To be defined in client
	Application* CreateApplication();
}
