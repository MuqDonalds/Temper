#include <Temper.h>

class Sandbox : public Temper::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Temper::Application* Temper::CreateApplication()
{
	return new Sandbox();
}