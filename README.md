# QApiDoc 0.1.0
***QApiDoc*** is a Qt library to generate swagger.json file for Swagger Spec version 2.0. Create a public documentation REST API using Swagger 2.0 for Qt/C++ Language. ***QApiDoc*** only responsibility is to generate the swagger.json file. The swagger.json file is responsible for containing all the documentation for your REST API. This file must be attached to the Swagger UI (User Interface) files. 



## Working architecture
>## Support
> Qt5, Qt6

## Prerequisits
>```bash
> mkdir myproject;
> cd myproject;
> git clone git@github.com:flaviomarcio/qapidoc.git;
>```
>Check example in qapidoc/example/*


## CMake Build information

>```
>## initial CMake parameters 
>
>-GNinja
>-DCMAKE_BUILD_TYPE:STRING=Debug
>-DCMAKE_PROJECT_INCLUDE_BEFORE:PATH=%{IDE:ResourcePath}/package-manager/auto-setup.cmake
>-DQT_QMAKE_EXECUTABLE:STRING=%{Qt:qmakeExecutable}
>-DCMAKE_PREFIX_PATH:STRING=%{Qt:QT_INSTALL_PREFIX}
>-DCMAKE_C_COMPILER:STRING=%{Compiler:Executable:C}
>-DCMAKE_CXX_COMPILER:STRING=%{Compiler:Executable:Cxx}
>-DCMAKE_INSTALL_PREFIX=~/build/myproject/install/release
>```

>```bash
> cd qapidoc
> mkdir build;
> cd build;
> cmake ..
> make;
> make install;
>```

## QMake Build information

>```bash
> cd qapidoc
> qmake qapidoc.pro
> make;
> make install;
> ls -l;
>```

## Configure QMake project

>```c++
>CONFIG += c++17
>CONFIG += console
>CONFIG += silent
>CONFIG -= debug_and_release
>QT += gui core widgets
>
>TEMPLATE = app
>TARGET = demo
>
>include($$PWD/../../../qapidoc/qapidoc.pri)
>```
## Implementation
>Using source of example of repository
>## Documentation for methods and classes
>Based on class/structs ***Qt*** and ***c++*** , create full documentation to ***OpenAPI***.
>```c++
>class PersonCrud : public QObject
>{
>    Q_OBJECT
>public:
>    Q_API_DOC_INFO(){
>        document->
>            host("localhost").
>            basePath("/v1/crud").
>            consumes("application/json").
>            produces("application/json").
>            schemes(stpsHttp);
>
>        document->info()
>            .title("Person CRUD V1")
>            .version("1.0.0")
>            .termsOfService("http://www.apache.org/licenses/LICENSE-2.0.txt")
>            .description("Sample API Description")
>            ;
>
>        document->info().contact()
>            .name("Flavio Portela")
>            .email("fmspxdev@gmail.com")
>            .url("https://github.com/flaviomarcio/qtreforce-sdk")
>            ;
>
>        document->info().license()
>            .name("Apache License - Version 2.0, January 2004")
>            .url("http://www.apache.org/licenses/LICENSE-2.0")
>            ;
>    }
>
>public:
>    explicit PersonCrud(QObject*parent=nullptr);
>
>    Q_API_DOC_PATH(search){
>        path->
>            operation(sptoGet)
>                .operationId({})
>                .responses(QApiResponse().statusCode(200))
>                .parameters(QApiParameter().name("id").typeParameter(QMetaType::QUuid))
>                .parameters(QApiParameter().name("name").required(true).type(QMetaType::QString));;
>    }
>    QVariant search();
>
>    Q_API_DOC_PATH(person){
>        path->
>            operation(sptoPost)
>                .operationId({})
>                .responses(QApiResponse().statusCode(200))
>                .parameters(QApiParameter().name("id").typeParameter(QMetaType::QUuid))
>                .parameters(QApiParameter().name("name").required(true).type(QMetaType::QString));
>
>        path->
>            operation(sptoPut)
>                .operationId({})
>                .responses(QApiResponse().statusCode(200))
>                .parameters(QApiParameter().name("id").typeParameter(QMetaType::QUuid))
>                .parameters(QApiParameter().name("name").required(true).type(QMetaType::QString));;
>
>        path->
>            operation(sptoDelete)
>                .operationId({})
>                .responses(QApiResponse().statusCode(200))
>                .parameters(QApiParameter().name("id").typeParameter(QMetaType::QUuid));
>    }
>    QVariant person();
>
>};
>```
>
>Extracting documentation
>```c++
>#include <QCoreApplication>
>#include <QDebug>
>#include <QProcess>
>#include <QJsonDocument>
>#include "./example_object.h"
>
>int main(int argc, char *argv[])
>{
>    QCoreApplication a(argc, argv);
>    
>    //documented class 
>    NotationExample::PersonCrud personCrud;
>
>    //export to QVariantHash
>    auto documentation=personCrud.documentation().toHash();
>
>    //export to Json
>    qDebug()<<QJsonDocument::fromVariant(documentation).toJson();
>
>    return QProcess::NormalExit;
>}
>```



## Swagger (Open API) - version 2.0

QApiDoc follows the specification 2.0 because it is more popular in the market and also because it is considered a more stable version to exist the longest. QApiDoc does not yet support the Swagger 3.0 version, but depending on the demand and contributions to the project it may evolve to support spec 3.0.

The main prerequisite for working with QApiDoc is to know the Swagger 2.0 specification that can be viewed in the link below.

https://github.com/OAI/OpenAPI-Specification/blob/master/versions/2.0.md

https://swagger.io/docs/specification/2-0/basic-structure/

## Json Schema

https://github.com/OAI/OpenAPI-Specification/blob/master/versions/2.0.md#schemaObject

http://json-schema.org

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

