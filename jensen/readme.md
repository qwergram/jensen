# Jensen

![](https://i.ytimg.com/vi/KnifMX8Yetg/maxresdefault.jpg)

Jensen is a queue implemented in C++, but wrapped with a Python interface. It is to serve as a lighter (and stealthier) weight version of [rabbitmq](https://www.rabbitmq.com/). You should use this library instead of rabbitmq if:

- You need a very simple queue, and you don't need rabbitmq's advanced exchanges
- You need RESTful API and not AMQP protocols to connect to the queue.
- The only thing you want to for setup is running an executable.
- _You're just trying to hack something together, with plans on moving to `rabbitmq`_

## Jensen's features

- Multiple Queue Support
- Methods to communicate with the queue directly
- Methods to communicate to the queue through REST APIs