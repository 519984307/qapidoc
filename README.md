# QApiDoc
QApiDoc is a Qt library to generate swagger.json file for Swagger Spec version 2.0. Create a public documentation REST API using Swagger 2.0 for Qt/C++ Language. QApiDoc's only responsibility is to generate the swagger.json file. The swagger.json file is responsible for containing all the documentation for your REST API. This file must be attached to the Swagger UI (User Interface) files. 

## Swagger (Open API) - version 2.0

QApiDoc follows the specification 2.0 because it is more popular in the market and also because it is considered a more stable version to exist the longest. QApiDoc does not yet support the Swagger 3.0 version, but depending on the demand and contributions to the project it may evolve to support spec 3.0.

The main prerequisite for working with QApiDoc is to know the Swagger 2.0 specification that can be viewed in the link below.

https://github.com/OAI/OpenAPI-Specification/blob/master/versions/2.0.md

https://swagger.io/docs/specification/2-0/basic-structure/

## Json Schema

https://github.com/OAI/OpenAPI-Specification/blob/master/versions/2.0.md#schemaObject

http://json-schema.org


## QApiDoc Speeches

https://www.youtube.com/watch?v=??????? (Pt-Br)

https://www.youtube.com/watch?v=??????? (Pt-Br)


## Swagger References and Tutorials 

https://swagger.io/swagger/media/blog/wp-content/uploads/2017/02/Documenting-An-Existing-API-with-Swagger-2.pdf

https://idratherbewriting.com/learnapidoc/pubapis_swagger_intro.html


## Swagger Tools

- Swagger:
https://swagger.io

- Swagger Editor:
https://editor.swagger.io

- Swagger Hub:
https://swagger.io/tools/swaggerhub

- The classic swagger sample:
http://petstore.swagger.io

- Tools and Integrations:
https://swagger.io/tools/open-source/open-source-integrations


## Swagger UI distribution files

For you to produce a page containing a Swagger documentation you need the Swagger UI distribution files.

These files you can find in the github swagger-api / swagger-ui repository.

https://github.com/swagger-api/swagger-ui/tree/master/dist

![image](https://user-images.githubusercontent.com/20048296/39937130-2925f868-5525-11e8-921d-c9ff0f59fefd.png)


First you need to download the swagger user interface files and generate the swagger.json file. You then need to change the index.html file to indicate the relative path of the location where the swagger.json file is located on your web server that is hosting the swagger user interface files.

See an example below.

![image](https://user-images.githubusercontent.com/20048296/39946376-49ad0df0-5544-11e8-8a5c-0980f5e6c257.png)
