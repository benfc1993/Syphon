#pragma once

#include "Event.h"

namespace Syphon
{
	class SYPHON_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode () { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent ( int keycode ) 
			: m_KeyCode ( keycode ) {}
		
		int m_KeyCode;
	};

	class SYPHON_API KeyPressedEvent : public KeyEvent
	{
	public: 
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		//If error change back to: 
		//inline int GetRepeatCount() const { return m_RepeatCount; }
		inline bool HasRepeated() const { return m_RepeatCount > 1; }

		std::string ToString () const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss;
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class SYPHON_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) 
			: KeyEvent(keycode) {}
		std::string ToString () const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str ();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}