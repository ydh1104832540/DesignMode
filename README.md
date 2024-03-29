# 设计模式

## 1.定义

设计模式是对用来在特定场景下解决一般设计问题的类和相互通信的对象的描述。

__注：每一个模式中稳定的部分就是该模式的缺点__

## 2.分类

### 2.1 创建型模式

__通过创建模式绕开new，来避免对象创建过程中所导致的紧耦合（依赖具体类），从而避免对象创建的稳定，它是接口抽象之后的第一步工作。__

- 工厂方法模式Factory Method
  - 定义一个用于创建对象的接口，让子类决定实例化那一个类。该方法使得一个类的实例化延迟（目的：解耦，手段：虚函数）到子类。
  - 用于隔离类对象的使用者和具体类型之间的耦合关系。面对一个经常变化的具体类型，紧耦合关系会导致软件的脆弱。
  
- 抽象工厂模式Abstract Factory

  - 提供一个接口，让接口负责创建一系列__相关或者相互依赖的对象__,无需指定它们具体的类。

  - 在软件系统中，经常面临着__一系列相互依赖的对象__的创建工作；同时，由于需求的变化，往往存在__更多系列对象__的创建工作。

    __系列对象__:指的是在某一特定系列下的对象之间有相互依赖、相互作用的关系。不同系列的对象之间不能相互依赖。

- 建造者模式Bulider

  - 在软件系统中，面临着一个复杂对象的创建工作，其通常由各个部分的子对象用一定的算法构成；由于需求的变化，这个复杂对象的各个部分经常面临着剧烈的变化，但是它们组合在一起的算法却相对稳定。
  - 将一个复杂对象的构建与表示相分离，使得同样的构建过程（稳定）可以创建不同的表示（变化）。
  - Bulider模式主要用于分步骤构建一个复杂的对象。在这其中分步骤是一个稳定的算法，而复杂对象的各个部分则经常变化。

- 原型模式

- 单例模式Singleton

  - 保证一个类只有一个实例，并提供一个该实例的全局访问点。

  - 在软件系统中，经常有这样一些特殊的类，必须保证它们在系统中只存在一个实例，才能确保它们的逻辑正确性、以及良好的效率。

### 2.2 结构型模式

- 适配器模式
- 桥接模式Bridge
  - 桥接模式属于单一职责模式，在软件组件的设计中，如果责任划分的不清晰，使用继承的结果往往是随着需求的变化，子类急剧膨胀，同时充斥着重复代码，这时候的关键是划清责任。
  - 动机：由于某些类型的固有的实现逻辑，使得它们具有多个变化的维度。
  - 将抽象部分（业务功能）与实现部分（平台）实现分离，使它们都可以独立地变化。
- 组合模式
- 装饰模式
- 外观模式
- 享元模式
- 代理模式

### 2.3 行为型模式

- 责任链模式
- 命令模式
- 解释器模式
- 迭代器模式
- 中介者模式
- 备忘录模式
- 观察者模式
- 状态模式
- 策略模式
- 模版方法模式
- 访问者模式