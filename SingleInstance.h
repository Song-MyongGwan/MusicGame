#pragma once
template <typename T>
class SingleInstance
{
public:
	static T* GetInstance()
	{
		static T* single = new T();

		return single;
	}
};