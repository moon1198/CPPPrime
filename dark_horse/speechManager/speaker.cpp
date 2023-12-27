#include "speaker.h"


Speaker::Speaker(int id, string name) : m_name(name), m_id(id) {
    m_score[0] = 0;
    m_score[1] = 0;
}