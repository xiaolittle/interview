// factor = number | (expression)
T factor(const char *s, int &p) {
  T value = 0;
  if (s[p] == '(') {
    ++p;
    value = expression(s, p);
    ++p;
  } else {
    value = 0;
    while (isdigit(s[p])) {
      value = value * 10 + s[p++] - '0';
    }
  }
  return value;
}

// term = factor { (*|/) factor}
T term(const char *s, int &p) {
  T value = factor(s, p), t = 0;
  while (s[p] == '*' || s[p] == '/') {
    char op = s[p++];
    t = factor(s, p);
    switch (op) {
      case '*': value *= t; break;
      case '/': value /= t; break;
    }
  }
  return value;
}

// expression = term { (+|-) term}
T expression(const char *s, int &p) {
  T value = term(s, p), t = 0;
  while (s[p] == '+' || s[p] == '-') {
    char op = s[p++];
    t = term(s, p);
    switch (op) {
      case '+': value += t; break;
      case '-': value -= t; break;
    }
  }
  return value;
}
