#include "racingexception.h"

RacingException::RacingException(const std::string& error)
	: m_error{ error }
{}

const char* RacingException::what() const noexcept { return m_error.c_str(); }
