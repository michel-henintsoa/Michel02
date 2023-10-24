#include <stdio.h>
#include <string.h>

int main() {
    char *content_type = "text/html";

    // Supprimez le cookie d'authentification pour déconnecter l'utilisateur.
    printf("Set-Cookie: authenticated=; Path=/; Expires=Thu, 01 Jan 1970 00:00:00 GMT; HttpOnly\n");
    printf("Status: 302 Found\n");
    printf("Cache-Control: no-store\n");
    printf("Location: http://www.exercice-login.mit/login.html\n\n");

    return 0;
}