#pragma once

#include <exception>
#include <string> 

class RacingException : public std::exception
{
public:
	RacingException(const std::string& error);

	const char* what() const noexcept;

private:
	std::string m_error;
};
