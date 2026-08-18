# 📡 Minitalk

> Communication inter-processus via signaux UNIX — projet 42

![C](https://img.shields.io/badge/Language-C-blue?style=flat-square)
![42](https://img.shields.io/badge/School-42-black?style=flat-square)
![Signals](https://img.shields.io/badge/IPC-SIGUSR1%20%7C%20SIGUSR2-orange?style=flat-square)

---

## 📖 Description

**Minitalk** est un programme de communication entre processus utilisant exclusivement les signaux UNIX `SIGUSR1` et `SIGUSR2`.

- Le **serveur** affiche son PID au démarrage et attend des messages.
- Le **client** encode chaque caractère en bits et les envoie signal par signal au serveur.

---

## ⚙️ Compilation

```bash
make        # compile server et client
make clean  # supprime les objets
make fclean # supprime tout
make re     # recompile
```

---

## 🚀 Utilisation

**1. Lancer le serveur**
```bash
./server
# Affiche son PID : [Server PID: 12345]
```

**2. Envoyer un message depuis le client**
```bash
./client <PID_DU_SERVEUR> "Votre message ici"
```

**Exemple :**
```bash
./server
# > [Server PID: 12345]

./client 12345 "Hello, World!"
# Le serveur affiche : Hello, World!
```

---

## 🧠 Fonctionnement

Chaque caractère est encodé sur **8 bits** :
- `SIGUSR1` → bit `0`
- `SIGUSR2` → bit `1`

Le serveur reconstruit chaque caractère bit par bit et l'affiche une fois les 8 bits reçus.

---

## 📁 Structure

```
minitalk/
├── Makefile
├── minitalk.h
├── server.c
└── client.c
```

---

## 📌 Fonctions autorisées

`write` · `signal` · `sigaction` · `kill` · `getpid` · `pause` · `sleep` · `usleep` · `exit` · `malloc` · `free`

---

## 👤 Auteur

**Randry** — [@github](https://github.com/)  
*42 School*
