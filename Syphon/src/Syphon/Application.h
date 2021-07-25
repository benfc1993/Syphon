#pragma once

#include "Core.h"

namespace Syphon
{
	class SYPHON_API Application
	{
	public:
		Application ();
		virtual ~Application ();

		void Run ();
	};

	//To be defined in client
	Application* CreateApplication ();
}

