#pragma once


#include <vector>
#include <functional>


namespace AlgoShiz 
{
	template <typename Ret, typename ...Args>
	using delegate = std::function<Ret(Args...)>;


	template <typename Ret, typename ...Args>
	class Event
	{
	private:
		using fn_t = delegate<Ret, Args...>;
		std::vector<fn_t> observers;
	public:
		void AddHandler(fn_t f)
		{
			observers.push_back(f);
		}

		void RemoveHandler(fn_t f)
		{
			auto place = std::find(observers.begin(), observers.end(), f);
			if (place != observers.end())
				observers.erase(observers.begin() + place);
		}

		void operator ()(Args... a)
		{
			Invoke(a...);
		}

		void Invoke(Args... a)
		{
			for (auto observer : observers)
				observer(a...);
		}
	};
}
