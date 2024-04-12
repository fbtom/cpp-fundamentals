#include "validation.hpp"

std::string getErrorMessage(const ErrorCode& error) {
    switch (error) {
    case ErrorCode::Ok:
        return "Ok";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs to have at least nine characters";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs to have at least one number";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs to have at least one special character";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs to have at least one uppercase letter";
        break;
    case ErrorCode::PasswordsDoNotMatch:
        return "Passwords do not match";
        break;
    default:
        return "";
    }
    return "";
}

bool doPasswordsMatch(const std::string& first_password, const std::string& second_password) {
    return first_password == second_password;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.size() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (std::none_of(password.begin(), password.end(), [](const auto& c) { return isdigit(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    std::vector<char> specialCharacters = {
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '<', '>', ':', ';', '\'',
        '"', '[', ']', '{', '}', '|', '\\', '/', '?', '.', ',', '`', '~', '=', '+'};
    bool has_special_character{false};
    for (char c : password) {
        if (std::find(specialCharacters.begin(), specialCharacters.end(), c) != specialCharacters.end()) {
            has_special_character = true;
        }
    }

    if (!has_special_character) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (std::none_of(password.begin(), password.end(), [](const auto& c) { return isupper(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& first_password, const std::string& second_password) {
    auto match{doPasswordsMatch(first_password, second_password)};
    if (!match) {
        return ErrorCode::PasswordsDoNotMatch;
    }
    return checkPasswordRules(first_password);
}