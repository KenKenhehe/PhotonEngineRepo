#pragma once
#include "Photon\Window.h"

#include <GLFW\glfw3.h>
namespace Photon {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		
		inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
		void SetVsync(bool enabled) override;
		bool IsVsync()override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData {
			std::string title;
			unsigned int Width, Height;
			bool vsync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}

