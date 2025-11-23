void strip_newline(char *s);

int main(void) {
    char s[] = "hello\n";
    strip_newline(s);
}

void strip_newline(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\n') {
            s[i] = '\0';
            return;
        }

        i++;
    }
}
