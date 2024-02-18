# QTonks

*Don't call me Nymphadora*

A library built on top of Qt Widgets that allows you to dynamically build UIs for displaying and 
editing settings based on a JSON schema


## Schema examples

```json
{
    "schema":
    [
        {
            "name": "enableSomeStuff",
            "type": "switch",
            "label": "Enable some stuff"
        },
        {
            "name": "someOptionWithChoices",
            "type": "enumeration",
            "label": "Enumeration",
            "options": [
                "one", "two", "three"
            ],
            "labels": [
                "Fancy label one",
                "Very fancy label two",
                "Not so fancy label three"
            ],
            "defaultOption": "one"
        },
        {
            "name": "input",
            "type": "string",
            "default": "aha!",
            "label": "Input stuff here"
        },
        {
            "name": "someIntegerValue",
            "type": "integer",
            "min": 0,
            "max": 100,
            "default": 42
        },
        {
            "name": "someGroup",
            "type": "group",
            "label": "Group of settings",
            "content": 
            [
                {
                    "name": "enableSomeGroupedStuff",
                    "type": "switch",
                    "label": "Enable some grouped stuff"
                },
                {
                    "name": "enableSomeOtherGroupedStuff",
                    "type": "switch",
                    "label": "Enable some other grouped stuff"
                },
                {
                    "name": "nestedGroup",
                    "type": "group",
                    "label": "Nested group of settings",
                    "content": 
                    [
                        {
                        "name": "nestedSwitch",
                        "type": "switch",
                        "label": "Wow!"
                        },
                    ]
                }
            ]
        }
    ]
}
```
