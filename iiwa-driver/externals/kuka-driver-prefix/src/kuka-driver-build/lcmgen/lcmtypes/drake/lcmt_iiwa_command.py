"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class lcmt_iiwa_command(object):
    __slots__ = ["timestamp", "num_joints", "joint_position", "num_torques", "joint_torque"]

    def __init__(self):
        self.timestamp = 0
        self.num_joints = 0
        self.joint_position = []
        self.num_torques = 0
        self.joint_torque = []

    def encode(self):
        buf = BytesIO()
        buf.write(lcmt_iiwa_command._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">qi", self.timestamp, self.num_joints))
        buf.write(struct.pack('>%dd' % self.num_joints, *self.joint_position[:self.num_joints]))
        buf.write(struct.pack(">i", self.num_torques))
        buf.write(struct.pack('>%dd' % self.num_torques, *self.joint_torque[:self.num_torques]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != lcmt_iiwa_command._get_packed_fingerprint():
            raise ValueError("Decode error")
        return lcmt_iiwa_command._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = lcmt_iiwa_command()
        self.timestamp, self.num_joints = struct.unpack(">qi", buf.read(12))
        self.joint_position = struct.unpack('>%dd' % self.num_joints, buf.read(self.num_joints * 8))
        self.num_torques = struct.unpack(">i", buf.read(4))[0]
        self.joint_torque = struct.unpack('>%dd' % self.num_torques, buf.read(self.num_torques * 8))
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if lcmt_iiwa_command in parents: return 0
        tmphash = (0xe0bb6ab386c61ece) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff)  + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if lcmt_iiwa_command._packed_fingerprint is None:
            lcmt_iiwa_command._packed_fingerprint = struct.pack(">Q", lcmt_iiwa_command._get_hash_recursive([]))
        return lcmt_iiwa_command._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

