int atoi(const char *str) {
  int num = 0;
  int sign = 1;
  const int n = strlen(str);
  int i = 0;
  while (str[i] == ' ' && i < n) i++;
  if (str[i] == '+') i++;
  if (str[i] == '-') {
      sign = -1;
      i++;
  }
  int temp = INT_MAX % 10;
  for (; i < n; i++) {
      if (str[i] < '0' || str[i] > '9')
          break;
      if (num > INT_MAX / 10 ||
                      (num == INT_MAX / 10 &&
                              (str[i] - '0') > temp)) {
          return sign == -1 ? INT_MIN : INT_MAX;
      }
      num = num * 10 + str[i] - '0';
  }
  return num * sign;
}