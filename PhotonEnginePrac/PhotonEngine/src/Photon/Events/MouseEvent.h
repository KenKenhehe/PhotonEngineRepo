#pragma once
#include "Event.h"

namespace Photon {
	class PHOTON_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) :
			m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Moved to " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class PHOTON_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(float xOffset, float yOffset) :
			m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrollEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class PHOTON_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) :
			m_Button(button) {}
		int m_Button;
	};

	class PHOTON_API MousePressedEvent : public MouseButtonEvent {
	public:
		MousePressedEvent(int button) :
			MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MousePressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class PHOTON_API MouseReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseReleasedEvent(int button) :
			MouseButtonEvent(button) {}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};


}