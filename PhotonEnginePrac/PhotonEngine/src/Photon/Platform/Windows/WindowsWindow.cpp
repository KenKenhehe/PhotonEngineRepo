#include "WindowsWindow.h"
namespace Photon {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	Photon::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void Photon::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Photon::WindowsWindow::SetVsync(bool enabled)
	{
		if (enabled) 
		{
			glfwSwapInterval(1);
		}
		else 
		{
			glfwSwapInterval(0);
		}

		m_Data.vsync = enabled;
	}

	bool Photon::WindowsWindow::IsVsync()
	{
		return m_Data.vsync;
	}

	void Photon::WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.title = props.Title;
		m_Data.Height = props.Height;
		m_Data.Width = props.Width;
		//TODO: log here
		if (!s_GLFWInitialized) 
		{
			int status = glfwInit();
			//TODO log here

			s_GLFWInitialized = true;

		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);

		SetVsync(true);
	}

	void Photon::WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}
