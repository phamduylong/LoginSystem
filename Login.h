#pragma once
#include <unordered_map>
#include <string>
#ifndef LOGIN_H
#define LOGIN_H
int takeInput();
void logIn(const std::unordered_map<std::string, std::string>& db);
void registerUser(std::unordered_map<std::string, std::string>& db);
void deleteUser(std::unordered_map<std::string, std::string>& db);
void printAllUsers(const std::unordered_map<std::string, std::string>& db);
#endif