#include "glamdict.h"

const uint8_t GLAM::dictID = 1;
const uint8_t GLAM::dictVer = 1;

const KourierTagDef glam_tag_list[] = {
    { GLAM::TAG_KEY_SN,KTag::KT_UINT32},
    { GLAM::TAG_KEY_BOX,KTag::KT_STRING},
    { GLAM::TAG_KEY_CELL,KTag::KT_STRING},
    { GLAM::TAG_KEY_PIN,KTag::KT_STRING},
    { GLAM::TAG_KEY_PUK,KTag::KT_STRING},
    { GLAM::TAG_KEY_APN,KTag::KT_STRING},
    { GLAM::TAG_KEY_APN_PASS,KTag::KT_STRING},
    { GLAM::TAG_KEY_APN_USER,KTag::KT_STRING},
    { GLAM::TAG_KEY_SW,KTag::KT_STRING},
    { GLAM::TAG_KEY_HW,KTag::KT_STRING},
    { GLAM::TAG_KEY_INDICATE,KTag::KT_UINT8},
    { GLAM::TAG_KEY_BAR,KTag::KT_UINT8},
    { GLAM::TAG_KEY_BATTERY,KTag::KT_UINT8},
    { GLAM::TAG_EVT_TYPE,KTag::KT_UINT8},
    { GLAM::TAG_LOCK_SN,KTag::KT_UINT32},
    { GLAM::TAG_LOCK_SEQ,KTag::KT_UINT32},
    { GLAM::TAG_LOCK_LAT,KTag::KT_UINT32},
    { GLAM::TAG_LOCK_LON,KTag::KT_UINT32},
    { GLAM::TAG_LOCK_TIME,KTag::KT_UINT32},
    { GLAM::TAG_LOCK_TAG,KTag::KT_BYTES},
    { GLAM::TAG_LOCK_STATUS,KTag::KT_STRING},
    { GLAM::TAG_LOCK_OPEN,KTag::KT_UINT8},
    { GLAM::TAG_LOCK_CLOSE,KTag::KT_UINT8},
    { GLAM::TAG_LOCK_DESC,KTag::KT_STRING},
    { GLAM::TAG_LOCK_TYPE,KTag::KT_UINT32},
    { GLAM::TAG_TRANS_TYPE,KTag::KT_UINT8},
    { GLAM::TAG_TRANS_START,KTag::KT_UINT32},
    { GLAM::TAG_TRANS_END,KTag::KT_UINT32},
    { GLAM::TAG_TRANS_RADUIS,KTag::KT_UINT32},
    { GLAM::TAG_TRANS_LAT,KTag::KT_UINT32},
    { GLAM::TAG_TRANS_LON,KTag::KT_UINT32},
    { GLAM::TAG_TRANS_ACK,KTag::KT_UINT8},
    { GLAM::TAG_TRANS_CNT,KTag::KT_UINT32},
    { GLAM::TAG_TRANS_REQ,KTag::KT_UINT8},
    { GLAM::TAG_TRANS_DURESS,KTag::KT_UINT8},
    { GLAM::TAG_SRV_NAME,KTag::KT_STRING},
    { GLAM::TAG_SRV_PORT,KTag::KT_UINT16},
    { GLAM::TAG_BIN_DATA,KTag::KT_BYTES},
    { GLAM::TAG_FILE_NAME,KTag::KT_STRING},
    { GLAM::TAG_FILE_SIZE,KTag::KT_UINT32},
    { GLAM::TAG_FILE_PACKET,KTag::KT_UINT32},
    { GLAM::TAG_FILE_CRC,KTag::KT_UINT16},
    { GLAM::TAG_FILE_VERSION,KTag::KT_UINT32},
    { GLAM::TAG_JSON_NAME,KTag::KT_STRING},
    { GLAM::TAG_JSON_PORT,KTag::KT_UINT16},
    { GLAM::TAG_KEY_MANUAL,KTag::KT_UINT8},
};


const uint8_t req_msg_set[] = { GLAM::TAG_KEY_SN };
const uint8_t req_msg_req[] = { GLAM::TAG_KEY_SN };
const uint8_t req_msg_evt[] = { GLAM::TAG_KEY_SN };

const KourierMsgDef glam_msg_list[] = {
    { GLAM::MSG_SET,sizeof(req_msg_set), req_msg_set },
    { GLAM::MSG_REQ,sizeof(req_msg_req), req_msg_req },
    { GLAM::MSG_ERR, 0, 0 },
    { GLAM::MSG_EVT,sizeof(req_msg_evt), req_msg_evt },
    { GLAM::MSG_TRANS, 0, 0 },
    { GLAM::MSG_DATA, 0, 0 },
    { GLAM::MSG_DEL, 0, 0 },
};


const KourierMetaDef glam_meta_list[] = {
0,0,0};

const uint8_t glam_tag_list_len = sizeof(glam_tag_list) / sizeof(KourierTagDef);
const uint8_t glam_msg_list_len = sizeof(glam_msg_list) / sizeof(KourierTagDef);
const uint8_t glam_meta_list_len = sizeof(glam_meta_list) / sizeof(KourierTagDef);

const KourierDictDef glam_dict_def = {
    GLAM::dictID,
    GLAM::dictVer,
    glam_msg_list_len,
    glam_tag_list_len,
    glam_meta_list_len,
    glam_msg_list,
    glam_tag_list,
    glam_meta_list
};

const KourierDictDef * GLAM::DictDef = &glam_dict_def;
