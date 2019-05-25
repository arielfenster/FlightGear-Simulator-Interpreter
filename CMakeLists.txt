cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(ex3 main.cpp Commands/Command.h
        Commands/ConnectCommand.cpp Commands/ConnectCommand.h
        Commands/OpenServerCommand.cpp Commands/OpenServerCommand.h Utils/CheckClass.cpp Utils/CheckClass.h DataReaderServer.cpp DataReaderServer.h
        Utils/ConditionParser.h Utils/ConditionParser.cpp Commands/IfCommand.cpp Commands/IfCommand.h Commands/LoopCommand.cpp Commands/LoopCommand.h
        Expressions/BinaryExpression.h Commands/Command.h Commands/DefineVarCommand.cpp Commands/DefineVarCommand.h Expressions/Div.h
        Expressions/Expression.h Expressions/Minus.h Expressions/Mult.h Expressions/Number.h Expressions/Plus.h
        Utils/ShuntingYard.cpp Utils/ShuntingYard.h Utils/SymbolTable.cpp Utils/SymbolTable.h
        User.cpp User.h Commands/SleepCommand.cpp Commands/SleepCommand.h Commands/PrintCommand.cpp
        Commands/PrintCommand.h Commands/EntercCommand.cpp Commands/EntercCommand.h Commands/ExitCommand.cpp
        Commands/ExitCommand.h Commands/RunCommand.cpp Commands/RunCommand.h)