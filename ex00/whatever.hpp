#pragma once

template <typename T>
void	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

//클래스안에서도 템플릿쓰는함수있으면 hpp파일에 선언&정의까지 해야됨

template <typename T>
T	min(T a, T b)
{
	if (b <= a)
		return (b);
	else
		return (a);
}

template <typename T>
T	max(T a, T b)
{
	if (b >= a)
		return (b);
	else
		return (a);
}