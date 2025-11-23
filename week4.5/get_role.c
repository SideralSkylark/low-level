const char *get_role(int id);

struct user {
    int id;
    const char *role;
};

struct user users[3] = {
    {1, "Admin"},
    {2, "Clerk"},
    {3, "Analist"}
};

int main(void) {
}

const char *get_role(int id) {
  for (int i = 0; i < 3; i++) {
        if (users[i].id == id) {
            return users[i].role;
        }
    } 

    return "Unkown";
}
