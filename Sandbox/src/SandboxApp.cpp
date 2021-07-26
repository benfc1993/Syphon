#include <Syphon.h>

class ExampleLayer : public Syphon::Layer
{
public:
	ExampleLayer() : Layer( "Example" )
	{
	}

	void OnUpdate() override
	{
	}

	void OnEvent(Syphon::Event& event) override
	{
		SY_TRACE( "{0} - Recieved: {1}",  event );
	}

};

class Sandbox : public Syphon::Application
{
public:
	Sandbox()
	{
		PushLayer( new ExampleLayer() );
	}

	~Sandbox()
	{
	}

};

Syphon::Application* Syphon::CreateApplication()
{
	return new Sandbox();
}
