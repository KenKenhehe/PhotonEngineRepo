#pragma once
#include "Event.h"

namespace Photon {
	class PHOTON_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	protected:
		KeyEvent(int keyCode) : m_KeyCode{ keyCode } {

		}

		int m_KeyCode;
	};

	class PHOTON_API KeyPressEvent : public KeyEvent {
	public:
		KeyPressEvent(int keyCode, int repeatCount) :
			KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: KeyCode = " << m_KeyCode << " (" << m_RepeatCount << ") Repeats";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;

	};

	class PHOTON_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) :
			KeyEvent(keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: KeyCode = " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	};

	class PHOTON_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int KeyCode) :
			KeyEvent(KeyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};


}