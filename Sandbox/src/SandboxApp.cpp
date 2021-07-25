#include <Syphon.h>

class Sandbox : public Syphon::Application
{
public: 
	Sandbox ()
	{
	}

	~Sandbox ()
	{
	}

};

Syphon::Application* Syphon::CreateApplication ()
{
	return new Sandbox ();
}
