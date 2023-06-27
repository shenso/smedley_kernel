# Smedley

Smedley is an API and plugin loader for Victoria 2, similar to Minecraft Forge. Smedley plugins can alter and enhance gameplay in ways that base Victoria 2 mods cannot, and have access to real game objects instead of relying on effects/triggers to change the game state.

# The Smedley Kernel

Smedley is made of two components, the bootstrapper (launcher) and kernel. The bootstrapper launches the game, and is responsible for injecting the kernel and the user's selected plugins into the game. The bootstrapper source can be found on the [project page.](https://github.com/shenso/smedley_bootstrapper)

The kernel is responsible for initializing plugins and the facilities used by them. Despite being separate components the bootstrapper will be bundled with releases on this project page.

## V2UP and 3rd party plugin disclaimer

V2UP is the flagship mod of Smedley and comes bundled with it. I intend to add various fixes and improvements to it that still mean to carry on the spirit of game.

Please keep in mind when installing 3rd party plugins that these are not Victoria 2 mods. These are dll files, and are capable of doing anything an exe file can do on your computer when loaded. Please only install and load plugins from sources you trust. I would suggest not using closed-source plugins. I may try to leverage the game's lua runtime or something similar to allow for sandboxing in the future.
