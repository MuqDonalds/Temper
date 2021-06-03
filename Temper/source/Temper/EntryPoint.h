#pragma once

#ifdef TP_PLATFORM_WINDOWS

extern Temper::Application* Temper::CreateApplication();

int main(int argc, char** argv)
{

	Temper::Log::Init();
	
	TP_CORE_ERROR("test");
	TP_CORE_CRITICAL("test");


	auto app = Temper::CreateApplication();
	app->Run();
	delete app;
}
#endif