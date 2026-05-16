# 1. ČÁST: Otevření souboru evropa.txt a vypsání na obrazovku
# Používáme blok 'with', který se postará o bezpečné uzavření souboru po skončení práce
print("--- PŮVODNÍ TEXT SOUBORU ---")
with open('evropa.txt', 'r', encoding='utf-8') as soubor:
    obsah = soubor.read()
    print(obsah)

# 2. ČÁST: Náhrada určitého znaku v textu jiným znakem
# Funkce replace() najde všechny výskyty prvního znaku a nahradí je druhým.
# Zde například nahradíme všechna malá písmena 'e' za zavináč '@'
zmeneny_text = obsah.replace('e', '@')

# 3. ČÁST: Uložení změněného textu do nového souboru
# Písmeno 'w' (write) znamená, že chceme do souboru zapisovat (pokud neexistuje, vytvoří se)
with open('evropa_upravena.txt', 'w', encoding='utf-8') as novy_soubor:
    novy_soubor.write(zmeneny_text)

print("\n--- HOTOVO ---")
print("Úprava proběhla úspěšně. Výsledek byl uložen do 'evropa_upravena.txt'.")