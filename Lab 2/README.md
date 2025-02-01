# Użycie klas odpowiadającym systemom operacyjnym: Windows, Linux, MacOs
W zadaniu chodzi o to, aby poćwiczyć używanie klas, a przy okazji poznać/przypomnieć/uzupełnić istotne różnice między systemami z punktu widzenia programowania dla różnych systemów.

Treść do wykonania:
---------
Klasa `Linux`:
Państwa zadaniem jest napisanie klasy Linux, która ma zawierać następujące składowe (typy do uzupełnienia):
1. `distribution_` - nie istnieje system Linux, systemami są jego dystrybucje.
   Jak nie wiadomo jaka dystrybucja to `Ubuntu`, więc wartość domyślna, ustawiana w klasie, to `"Ubuntu"`.
    1. Proszę do niej utworzyć metodę do odczytu `distribution()`.
2. `std::size_t open_source_system_users_` - jest to ilość użytkowników Linuxa, wspólna dla wszystkich klas.
   W konstruktorze powinna być zwiększana, w destruktorze zmniejszana.
    1. Proszę do niej utworzyć statyczną metodę do odczytu `open_source_system_users()`
3. `users_` - są to użytkownicy systemu, typ dowolny, polecam jednak `std::vector`.
   Struktura na użytkowników jest w pliku `user.h`
4. `character_type` - jest to przezwisko typu `char`

Oraz następujące metody (poza powyższymi getterami):
1. Konstruktor bezargumentowy, powinien on wypisywać: `"+" << distribution_ << '\n'`, oraz inkrementować `open_source_system_users_`
    - Jakbyśmy nie zdefiniowali konstruktora domyślnego to co by się stało?
2. Konstruktor przyjmujący dystrybucje, powinien robić co powyższy jw.
    - O czym jeszcze powinienem paniętać aby `open_source_system_users_` faktycznie przy każdej konstrukcji się zwiększało?
3. Destruktor, który będzie dekrementował `open_source_system_users_`, oraz wyświetlał `"~" << distribution_ << '\n'`
    - jakbyśmy nie zdefiniowali destruktora to co by się stało?
4. Metodę `add_user` zwracającą id kolejnego użytkownika (czyli ilość elementów `users_` - 1), przyjmującą `user_name` i `password`.
   Nowy użytkownik powinien być dodany do `users_`.
5. Metodę `user`, która przyjmując `user_id` zwróci konkretnego użytkownika
6. Metodę `user_home_directory`, która przyjmując `user_id` zwróci ścieżkę do katalogu użytkownika, czyli `/home/username/`
7. *Środowisko graficzne dla dystrybucji, nie każdy ją ma. Dlatego proszę o dodanie:
    1. dodanie `#include <optional>`, wtedy też pojawi się makro: `__cpp_lib_optional` aktywujące testy ([szczegóły](https://en.cppreference.com/w/User:D41D8CD98F/feature_testing_macros))
    2. Pola w klasie: `std::optional<std::string> graphic_environment_;`
    3. Metod dostępowych: `graphic_environment() const` i `set_graphic_environment`
8. *Zachęcam jeszcze do implementacji następujących metod:
    1. `static std::string default_text_file_encoding()` - domyślny system kodowania plików tekstowych
    2. `static std::string end_of_line()` - znak/znaki na końcu każdej linii
    3. `constexpr static bool is_path_case_sensitive()` - czy w ścieżkach wielkość znaków ma znaczenie
    4. `constexpr static char path_separator()` - jaki separator występuje w ścieżce do pliku lub katalogu
    5. `static std::string shortcut_to_send_end_of_file_to_program()` - jakim skrótem klawiszowym wysłać do programu EOF - end of file
    6. `static std::pair<std::string, std::string> user_login_information()` - ma to zwrócić ścieżki do plików `/etc/passwd` i `/etc/shadow`
        - co to są za pliki?
    7. `static std::string users_directory()` - ma zwrócić domyślną ścieżkę, gdzie tworzone są katalogi użytkowników
    - **Mają one pomóc w lepszym zrozumieniu istotnych, z punktu widzenia programowania, różnic między systemami.**

---------
Klasa `Windows`:
Państwa zadaniem jest napisanie klasy Windows, która ma zawierać następujące składowe (typy do uzupełnienia):
1. `version_` - wersja, wartość domyślna, ustawiana w klasie, to `"11"`.
    1. Proszę do niej utworzyć metodę do odczytu `version()`.
2. `std::size_t activated_systems_` - jest to ilość aktywowanych Windowsów, wspólna dla wszystkich klas.
   W konstruktorze powinna być zwiększana.
    1. Proszę do niej utworzyć statyczną metodę do odczytu `activated_systems()`
3. `users_` - są to użytkownicy systemu, typ dowolny, polecam jednak `std::vector`.
   Struktura na użytkowników jest w pliku `user.h`
4. `character_type` - jest to przezwisko typu `wchar_t`

Oraz następujące metody (poza powyższymi getterami):
1. Konstruktor bezargumentowy, powinien on wypisywać: `"Windows " << version_ << '\n'`, oraz inkrementować `activated_systems_`
    - Jakbyśmy nie zdefiniowali konstruktora domyślnego to co by się stało?
2. Konstruktor przyjmujący dystrybucje, powinien robić co powyższy jw.
    - O czym jeszcze powinienem paniętać aby `activated_systems_` faktycznie przy każdej konstrukcji się zwiększało?
3. Metodę `add_user` zwracającą id kolejnego użytkownika (czyli ilość elementów `users_` - 1), przyjmującą `user_name` i `password`.
   Nowy użytkownik powinien być dodany do `users_`.
4. Metodę `user`, która przyjmując `user_id` zwróci konkretnego użytkownika
5. Metodę `user_home_directory`, która przyjmując `user_id` zwróci ścieżkę do katalogu użytkownika, czyli `C:\Users\username\`
6. *Zachęcam jeszcze do implementacji następujących metod:
    1. `static std::string default_text_file_encoding()` - domyślny system kodowania plików tekstowych
    2. `static std::string end_of_line()` - znak/znaki na końcu każdej linii
    3. `constexpr static bool is_path_case_sensitive()` - czy w ścieżkach wielkość znaków ma znaczenie
    4. `constexpr static char path_separator()` - jaki separator występuje w ścieżce do pliku lub katalogu
    5. `static std::string shortcut_to_send_end_of_file_to_program()` - jakim skrótem klawiszowym wysłać do programu EOF - end of file
    6. `static std::pair<std::string, std::string> user_login_information()` - ma to zwrócić ścieżki do plików: https://stackoverflow.com/a/5915362/1350091
        - co to są za pliki?
    7. `static std::string users_directory()` - ma zwrócić domyślną ścieżkę, gdzie tworzone są katalogi użytkowników
    - **Mają one pomóc w lepszym zrozumieniu istotnych, z punktu widzenia programowania, różnic między systemami.**
7. Po dokonaniu implementacji proszę zakomentować makro `UNIMPLEMENTED_WINDOWS_CLASS`
