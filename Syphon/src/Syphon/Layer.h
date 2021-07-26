#pragma once

#include "Syphon/Core.h"
#include "Syphon/Events/Event.h"

namespace Syphon
{
	class SYPHON_API Layer
	{
	public:
		Layer( const std::string& debugName = "Layer" );
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetatch() {}
		virtual void OnUpdate() {}
		virtual void OnEvent( Event& event ) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

}

