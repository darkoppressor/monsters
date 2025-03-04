# monsters

[![Build Status](https://wells-family.xyz/jenkins/buildStatus/icon?job=monsters)](https://wells-family.xyz/jenkins/job/monsters/)

A game in development by Cheese and Bacon Games
https://cheeseandbacon.org/

This is the source code for a game currently being developed by Cheese and Bacon Games.

## For players

* [System requirements](docs/systemRequirements.md)
* [Changelog](docs/changelog.md)

## For developers

* [Ideas](development/ideas.md)
* [To do](development/toDo.md)

* [AI goals](development/design/aiGoals.md)
* [Consumable](development/design/consumable.md)
* [Creature](development/design/creature.md)
* [Damage Type](development/design/damageType.md)
* [Equipment](development/design/equipment.md)
* [Faction](development/design/faction.md)
* [Item](development/design/item.md)
* [Race](development/design/race.md)
* [Race Category](development/design/raceCategory.md)
* [Relationship](development/design/relationship.md)
* [Stats](development/design/stats.md)
* [World](development/design/world.md)

### Updating the version

    ~/build-server/cheese-engine/tools/version <PROJECT-DIRECTORY> <VERSION-COMPONENT> [STATUS]
    ~/build-server/cheese-engine/tools/build-date <PROJECT-DIRECTORY>

In version.cpp:

    Update the version series in Engine_Version::populate_version_series to include the new version

When an updated version has been pushed to main, tag the commit locally and remotely:

    git tag <VERSION> -m "<VERSION>"
    git push origin tag <VERSION>

## License

This game's source code is licensed under the MIT License. See [LICENSE.md](docs/LICENSE.md) for the full license text.

This game's data is not under the same license as the source code. See [contentLicense.md](docs/contentLicense.md) for
game data licensing details.

For third party licenses for dependencies, see [the thirdPartyLicenses directory](docs/thirdPartyLicenses).
