# Model declaration
class Pokemon(object):
    def __init__(self, name, attribute, CP):  # attribute as type
        self.name = name
        self.attribute = attribute
        self.CP = CP


# List of Pokemon with initial pokemons
pokemons = [Pokemon("妙蛙種子", "grass", 100), Pokemon("小火龍", "fire", 100), Pokemon("傑尼龜", "water", 100)]


# Functions declaration
def displayMainMenu():
    while True:
        actionCode = int(input("選擇1.新增 2.對戰 3.結束:"))
        if actionCode == 1:
            addNewPokemon()
        elif actionCode == 2:
            battle()
        elif actionCode == 3:
            break
        else:
            print("輸入錯誤\n")


def addNewPokemon():
    newName = input("輸入名字:")
    newAttribute = input("輸入屬性:")
    while newAttribute != 'fire' and newAttribute != 'grass' and newAttribute != 'water':
        print("輸入錯誤")
        newAttribute = input("輸入屬性:")
    newCP = int(input("輸入CP值:"))

    pokemons.append(Pokemon(newName, newAttribute, newCP))
    print("新增完畢\n")


def battle():
    for (i, pokemon) in enumerate(pokemons, start=0):
        print(f"編號{i}\n名字:{pokemon.name}\n屬性:{pokemon.attribute}\nCP值:{pokemon.CP}")

    firstPick = int(input("選擇第一隻（輸入編號）"))
    if 0 < firstPick or firstPick > 5:
        pass
    while 0 < firstPick > len(pokemons) - 1:
        print("輸入錯誤")
        firstPick = int(input("選擇第一隻（輸入編號）"))
    firstPokemon = pokemons[firstPick]

    secondPick = int(input("選擇第二隻（輸入編號）"))
    while 0 < secondPick > len(pokemons) - 1:
        print("輸入錯誤")
        secondPick = int(input("選擇第二隻（輸入編號）"))
    secondPokemon = pokemons[secondPick]

    # Different CP
    if firstPokemon.CP > secondPokemon.CP:
        print(f"編號{firstPick} {firstPokemon.name} 勝利\n")
    elif secondPokemon.CP > firstPokemon.CP:
        print(f"編號{secondPick} {secondPokemon.name} 勝利\n")
    elif firstPokemon.CP == secondPokemon.CP:
        # Same CP
        # Fire vs Grass
        if firstPokemon.attribute == "fire" and secondPokemon.attribute == "grass":
            print(f"編號{firstPick} {firstPokemon.name} 勝利\n")
        elif secondPokemon.attribute == "fire" and firstPokemon.attribute == "grass":
            print(f"編號{secondPick} {secondPokemon.name} 勝利\n")
        # Grass vs Water
        if firstPokemon.attribute == "grass" and secondPokemon.attribute == "water":
            print(f"編號{firstPick} {firstPokemon.name} 勝利\n")
        elif secondPokemon.attribute == "grass" and firstPokemon.attribute == "water":
            print(f"編號{secondPick} {secondPokemon.name} 勝利\n")
        # Water vs Fire
        if firstPokemon.attribute == "water" and secondPokemon.attribute == "fire":
            print(f"編號{firstPick} {firstPokemon.name} 勝利\n")
        elif secondPokemon.attribute == "water" and firstPokemon.attribute == "fire":
            print(f"編號{secondPick} {secondPokemon.name} 勝利\n")


# Program start here
displayMainMenu()
