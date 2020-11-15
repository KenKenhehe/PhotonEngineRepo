#pragma once
#include "Photon\PhPch.h"

#include "Photon\Core.h"
#include "Photon\Events\Event.h"

namespace Photon
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Photon Engine",
			unsigned int width = 1280,
			unsigned int height = 720) : 
			Title(title), Width(width), Height(height){}
	};

	class PHOTON_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool IsVsync() = 0;

		static Window* Create(const WindowProps & = WindowProps());
	};


}