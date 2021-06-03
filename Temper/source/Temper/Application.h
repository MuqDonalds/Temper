#pragma once

#include "Core.h"

namespace Temper {


	class TEMPER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};


	//To be declared in client
	Application* CreateApplication();


}
