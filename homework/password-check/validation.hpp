#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoNotMatch
};

std::string getErrorMessage(const ErrorCode& error);
bool doPasswordsMatch(const std::string& first_password, const std::string& second_password);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& first_password, const std::string& second_password);