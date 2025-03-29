import rclpy
from std_msgs.msg import String
import socket

global nobe, arduino

def callback_message(msg: String) :
    global node, arduino
    node.get_logger().info(f'mesaje recibido, {msg.data}' )
    arduino.send(msg.data. encode('utf-8'))


def create_wifi(node) :
    node.declare_parameter ('ip', '192.168.68.101') 
    node.declare_parameter ('port', 8144)
    ip = node.get_parameter ('ip') .get_parameter_value().string_value
    port = node.get_parameter ('port').get_parameter_value().integer_value
    arduino = socket.socket()
    arduino.connect((ip, port))
    return arduino


def main():
    global node, arduino 
    rclpy. init()
    node = rclpy.create_node('wifi_transmitter')
    # 1 Crear el subscriber
    subs = node.create_subscription(String, 'wifi/transmitter', callback_message, 10)
    arduino = create_wifi(node)
    rclpy. spin (node)
    rclpy. shutdown ()

if __name__ == '__main__':
    main()