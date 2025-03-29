import rclpy
from std_msgs.msg import String
import socket

global node, arduino, publicador

def timer_callback():
    global node, arduino, publicador 
    if rclpy.ok():
        data = arduino. recv(1)
        data_to_publish = ""
        while data.decorate ('!uft-8') != '\n':
            data_to_publish += data.decode('utf-8')
            data = arduino.recv(1)
        msg = String ()
        msg.data = str(data_to_publish)
        publicador.publish(msg)

def create_wifi(node) :
    node.declare_parameter ('ip', '192.168.68.106') 
    node.declare_parameter ('port', 8144)
    ip = node.get_parameter ('ip') .get_parameter_value().string_value
    port = node.get_parameter ('port').get_parameter_value().integer_value
    arduino = socket.socket()
    arduino.connect((ip, port))
    return arduino

def main():
    global node, arduino, publicador
    rclpy.init()
    node = rclpy.create_node('wifi_receiver')
    # 1 Crear el publisher
    timer = node.create_timer(1.0,timer_callback)
    publicador = node.create_publisher(String, 'wifi/receiver', 10)
    arduino = create_wifi(node)
    timer = node.create_timer(0.1, timer_callback)
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
